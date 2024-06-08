georgii@georgiis-MBP raylib_test % clang -o my_app main.c -I/Users/georgii/raylib/build/raylib/include -L/Users/georgii/raylib/build/raylib -lraylib -framework Cocoa -framework IOKit -framework CoreVideo -framework OpenGL



georgii@georgiis-MBP raylib_test % emcc main.c -o index.html -O3 \
-s USE_GLFW=3 -s WASM=1 -s ASYNCIFY \
-I/Users/georgii/raylib/build_wasm/raylib/include \
-L/Users/georgii/raylib/build_wasm/raylib \
-lraylib \
-s USE_WEBGL2=1 \
-s TOTAL_MEMORY=67108864