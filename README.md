# TownCrier

An endpoint for GDP routers. It doesn't implement any routing protocol, just listens on a port to hear messages.

Jobs:
- [ ] Send messages into the network from local names.
- [ ] Receive message from the network and route it to local names, using UNIX sockets? IO-uring?
- [ ] C++ connector code.
- [ ] Advertise listening GDP names in the local machine. (Stop using persistent TCP connections in lieu of messages sent by the GDP router.)