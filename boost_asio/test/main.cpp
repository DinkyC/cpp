#include <iostream>
#include <string>

// for brute force pause
#include <chrono>
#include <thread>

// Macro to ensure that we don't pull in the rest of boost library
#define ASIO_STANDALONE
// #include <asio/ip/tcp.hpp>
// #include <asio/error_code.hpp>
// #include <asio/io_context.hpp>

// main header file
#include <asio.hpp>
// Buffers
#include <asio/ts/buffer.hpp>
// For network communication 
#include <asio/ts/internet.hpp>

// Create buffer for asynchronyse reading of response
// Can control how much data gets read on each read command
std::vector<char> vBuffer(20 * 1024);

// Lambda function to asynchronysly read data from the response
void GrabSomeData(asio::ip::tcp::socket& socket)
{
    socket.async_read_some(asio::buffer(vBuffer.data(), vBuffer.size()),
        [&](std::error_code ec, std::size_t length)
        {
            if (!ec)
            {
                std::cout << "\n\nRead " << length << " bytes\n\n" << std::endl;
                for (int i = 0; i < static_cast<int>(length); i++) {
                    std::cout << vBuffer[i];

                }
                GrabSomeData(socket);
            }
        }
    );
}

int main()
{
    // for handling error codes
    asio::error_code ec;
    
    // Create a "context" - essentially the platform specific interface
    asio::io_context context;

    // Give some fake tasks to asio so the context doesn't finish
    asio::io_context::work idleWork(context);

    // Start the context
    std::thread theContext = std::thread([&]() { context.run(); });

    // Use a resolver to be able to convert a hostname to an ip address
    asio::ip::tcp::resolver resolver(context);
   
    // Assign the hostname and port
    auto endpoints = resolver.resolve("google.com", "80", ec);

    if (ec)
    {
        std::cout << "failed to resolve" << ec.message() << std::endl;
        return -1;
    }

    // Get the address of somewhere we wish to connect to
    // asio::ip::tcp::endpoint endpoint(asio::ip::make_address("hightimesesp.com", ec), 80);
    
    // Create the socket on the local device and connect to the network drivers
    asio::ip::tcp::socket socket(context);

    // Connect to the endpoints
    asio::connect(socket, endpoints, ec);

    if (!ec)
    {
        std::cout << "connected" << std::endl;
    }
    else 
    {
        std::cout << "Failed to connect to: \n" << ec.message() << std::endl;
    }

    if (socket.is_open())
    {
        GrabSomeData(socket);
        // the data that will be sent to the server
        std::string sRequest = 
            "GET /index.html HTTP/1.1\r\n"
            "Host: google.com\r\n"
            "connection: close \r\n\r\n";

        // send the data to the server
        socket.write_some(asio::buffer(sRequest.data(), sRequest.size()), ec);
        
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(2000ms);
       
        // wait until any data is available
        // socket.wait(socket.wait_read);
        //
        // size_t bytes = socket.available();
        // std::cout << "bytes available: " << bytes << std::endl;
        // if (bytes > 0) 
        // {
        //     std::vector<char> vBuffer(bytes);
        //     socket.read_some(asio::buffer(vBuffer.data(), vBuffer.size()), ec);
        //     // print out the contents of the buffer
        //     for (auto c : vBuffer) {
        //         std::cout << c;
        //     }
        // }

    }

    system("read -n 1 -s -r -p 'Press any key to continue'");
    std::cout << std::endl;

    return 0;
}
