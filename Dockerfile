FROM drogonframework/drogon:latest
RUN apt-get update && apt-get install -y \
    libboost-all-dev
WORKDIR /app
COPY mk_robotics .
RUN mkdir build && cd build && cmake .. && make
WORKDIR /app/build
CMD ["./mk_robotics"]