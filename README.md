# signal_subscriber_pattern
Asynchronous communication between signals and subscribers. 

This is a mechanism that facilitates asynchronous communication between signals and subscribers. The signal is sent to a scheduler, which takes ownership of it.

The scheduler maintains a registry of subscribers (without ownership) and their particular "signal kind" interests. Using this registry, the scheduler dispatches the signal to the appropriate subscriber. The subscriber receives the signal and processes it further.

