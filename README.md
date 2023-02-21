# broadcaster_subscriber_pattern
Asynchronous communication between broadcasters and subscribers. 

This is a mechanism that facilitates asynchronous communication between broadcasters and subscribers. The broadcaster sends the event to a scheduler, which takes ownership of it.

The scheduler maintains a registry of subscribers (without ownership) and their particular "broadcaster" interests. Using this registry, the scheduler dispatches the event to the appropriate subscriber. The subscriber receives the event and processes it further.

