#############
#  PROBLEM  #
#############

**Description**

- Given a social network containing n members and a log file containing m timestamps
  representing the time that the friendships (connections) were formed, produce an 
  algorithm that determines the earliest time (root) at which all members ALL members 
  are connected.

################
# ASSUMPTIONS  #
################

1. The logfile is sorted by timestamp

2. Friendship is an equivalence relationship of timestamps

#############
#  EXAMPLE  #
#############

time  m#1  m#2
----|----|----|
 1    0    1 
----|----|----|
 2    2    0
----|----|----|

1. 

- input = [(1700694967, 0, 1) , (1700694969, 0, 2), (1700694977, 2, 3)] 
- output = 

2.

- input = [1,3,1,2,5]
- output = 

