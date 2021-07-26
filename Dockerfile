FROM drogonframework/drogon:latest
WORKDIR /app
COPY mk_robotics .
RUN mkdir build && cd build && cmake .. && make
CMD ["build/mk_robotics"]