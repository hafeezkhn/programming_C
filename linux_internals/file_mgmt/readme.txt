-------------------	FILE_MANAGEMENT      -----------------------------------------------

POSIX -> (Portable Operating System Interface)IEEE defined standards Enables software 
portability across operating systems,it defines both system and user-level APIs
glibc -> impliments APIs on GNU/Unix based OS
file -> is data container
file system -> file resides in a filesystem( way of organising the data), fs will be hosted on memory(disk,ram,etc..)
	#partitioning:[[MBR],[PartitionTable],[DiskPartition]]
						     /
			[[BootBlock],[SuperBlock],(InodeBlock),(DataBlocks)]
	#each partition may be raw,or host some file system


(CMD) cat /proc/filesystem


