API:
    REST:
        req:
            http://127.0.0.1/mk_robotics/api/v1/dummy/data?data={}
        res:
            id: int <0,10>
            data: string {data}
    WS:
        onConnected:
            data: OK XD
        onMessage(data):
            data: {data}
Docker:
    docker build -t  mk_rest .
    docker run -it --network host mk_rest