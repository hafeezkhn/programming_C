(Notes)

------------------------------------------
SERVER SIDE
------------------------------------------
1. server config   -- UDP
   -> getaddrinfo()
   -> socket()
   -> bind()

2. server config   -- TCP
   -> getaddrinfo()
   -> socket()
   -> bind()
   -> listen()
   -> accept()

3. once connection is established
   -> recv()
   -> send()

------------------------------------------
CLIENT SIDE
------------------------------------------
1. for httpserver - local host 
   -> 127.0.0.1:8080 - from browser 

2. client config --TCP
   -> getaddrinfo()
   -> socket()
   -> connect()
   -> send() and recv()
   -> close()



