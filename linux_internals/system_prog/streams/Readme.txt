Data structure : serialized buffer/Streams

--> helps copying bytes into buffer , as well as reading bytes from the buffer.
--> flexible buffer
--> collect/append data packets one after the other
    
      network packet-> [whatsup.....][.........App2.........][....A,d....][ MAC-A  ]
    (packets appended)  appdata       transport layer header  network hdr   mac hdr  


   typedef struct serialized_buffer{
            char *b; //points start of the memory buffer which stores data
            int size; // size of serialised buffer
            int next;//byte position in serialised buffer where next datta item will be written/read
     }ser_buff_t;
                
      |<--------size--------->|
      [....DATA....][available]
      ^            ^ 
      |            |
   char *b        next

