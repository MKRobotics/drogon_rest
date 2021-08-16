# Drogon Rest
### HTTP interface for comunnication with _mk_robotics_ motors.

#### Build

- docker build -t <name_of_image> . 
- docker run -it --network host mk_rest <name_of_image> 

#### API
##### WebSocket
###### Endpoint
- ws://127.0.0.1/data 

###### Data
- id: number
- content: string
- type: string
- timestamp: data
- priority: number
