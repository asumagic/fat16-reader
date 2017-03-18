# FAT16 reader

This is a simple C++ project aiming to read FAT16 partitions.

It is currently capable to read the MBR of a device dump or directly from a device (using `/dev/sd*` on Linux and likely MacOS). Currently, it can read a FAT16 partition's bootsector.

Basic file and directory reading capabilities will be added in the future.
