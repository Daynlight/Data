result=${PWD##*/}
result=${result:-/}

if [ "$result" == ".github" ]; then
    cd ..
fi

git submodule update --remote

cmake .
cmake --build . --config Debug
cmake --build . --config Release

start "" "Main.sln"

if [ "$result" == ".github" ]; then
    cd .github
fi

exit 0