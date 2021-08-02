FROM drogonframework/drogon:latest
WORKDIR /app
COPY mk_robotics .
RUN mkdir build && cd build && cmake .. && make
WORKDIR /app/build
CMD ["./mk_robotics"]