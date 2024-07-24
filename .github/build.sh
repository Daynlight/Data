mkdir prod

git submodule update --remote
mkdir build
cd build
cmake ..
cmake --build . --config Release
cd ..

cp build/Release/CPP-DATA.lib prod/CPP-DATA.lib
cp CPP-DATA/Data.h prod/Data.h
cp LICENSE prod/LICENSE

rm -r build/