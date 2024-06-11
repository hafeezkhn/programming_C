_______________________________________________
LDD---------------------------------------------

1.Download boot images and root file system(rfs)
	via sdcard
  --> for booting we need both rfs and image
      <-----512-BOOT------->_____ROOTFS______
     |FS type:FAT16        |FS Type:EXT4     |
     | this partition holds| this partition  |
     | boot images like    | holds debian-rfs|
     | MLO,uboot & kern img|                 |
     |      Partition 1    |  Partition 2    |
     `````````````````````````````````````````
  -->
