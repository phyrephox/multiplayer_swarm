cmd_Release/obj.target/addon/boid.o := g++ '-D_LARGEFILE_SOURCE' '-D_FILE_OFFSET_BITS=64' '-DBUILDING_NODE_EXTENSION' -I/home/alex/.node-gyp/0.10.35/src -I/home/alex/.node-gyp/0.10.35/deps/uv/include -I/home/alex/.node-gyp/0.10.35/deps/v8/include  -fPIC -Wall -Wextra -Wno-unused-parameter -pthread -m64 -O2 -fno-strict-aliasing -fno-tree-vrp -fno-omit-frame-pointer -fno-rtti -fno-exceptions -MMD -MF ./Release/.deps/Release/obj.target/addon/boid.o.d.raw  -c -o Release/obj.target/addon/boid.o ../boid.cc
Release/obj.target/addon/boid.o: ../boid.cc ../boid.h ../vector.h
../boid.cc:
../boid.h:
../vector.h: