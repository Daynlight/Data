mkdir prodLib
cd prodLib
git clone -b Lib https://github.com/Daynlight/CPP-Data .
cd ..

git submodule update --remote
mkdir build
cd build
cmake ..
cmake --build . --config Release
cd ..

cp build/Release/CPP-DATA.lib prodLib/Data.lib
cp CPP-DATA/Data.h prodLib/Data.h
cp LICENSE prodLib/LICENSE

rm -r build/

mkdir prodRelease
cd prodRelease
git clone -b Release
cd ..

cp -r CPP-DATA/* prodRelease/