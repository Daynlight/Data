cd ..

git submodule update --remote

cmake .
cmake --build . --config Debug
cmake --build . --config Release

start "" "Main.sln"

cd .github

exit ""