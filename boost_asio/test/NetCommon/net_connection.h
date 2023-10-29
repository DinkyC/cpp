#pragma once

#include "net_common.h"
#include "net_tsqueue.h"
#include "net_message.h"

namespace olc 
{
    namespace net 
    {
        template<typename T>
        class connection : public std::enable_shared_from_this<connection<T>>
        {
            public:
                // A connection is "owned" by either a server or a client, and its
                // behaviour is slightly different bewteen the two.
                enum class owner
                {
                    server,
                    client
                };

            public:
                connection()
                {}

                virtual ~connection()
                {}

                // This ID is used system wide - its how clients will understand other clients
                // exist across the whole system.
                // uint32_t GetID() const
                // {
                //     return id;
                // }

            public:
                bool ConnectToServer();
                bool Disconnect();
                bool IsConnected() const;

            public:
                bool Send(const message<T>& msg);

            protected:
                // Each connection has a unique socket to a remote
                asio::ip::tcp::socket m_socket;
                
                // This context is shared with the whole asio instance
                asio::io_context& m_asioContect;
                
                // This queue holds all messages to be sent to the remote side
                // of this connection
                tsqueue<message<T>> m_qMessagesOut;
                
                // This queue holds all messages that have been recieved from 
                // the remote side of this connection. Not it is a reference
                // as the "owner" of this connection is expected to provide a queue
                tsqueue<owned_message<T>>& m_qMessagesIn;


        };
    }
}

