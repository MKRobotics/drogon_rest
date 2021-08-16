API:
    WS:
        ws://127.0.0.1/data
Docker:
    docker build -t  mk_rest .
    docker run -it --network host mk_rest
