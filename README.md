# FAT16 reader

This is a simple C++ project aiming to read FAT16 filesystems.

It is currently capable to read the MBR of a device dump or directly from a device (using `/dev/sd*` under Linux and MacOS). In its current state, it will automatically list all the files of the root directory with minimal information. Listing subdirectories and files is planned. Writing data is not.

This is meant to be a demo for using FAT16 filesystem.

API Usage :

```cpp
std::ifstream device{"somedevice.dump", std::ios::binary};

// Read and parse the MBR for the device dump
mbr::MBR mbr{device};

// Iterate over every partition found on the MBR
for (mbr::Partition& mbr_entry : mbr.partitions)
{
    // (Temporary) Verify for the partition to be present
    if (mbr_entry.data.type)
    {
        // Read and prepare the FAT16 filesystem at the given sector
        fat::Filesystem part{dump, mbr_entry.data.start_sector};
    }
}
```
