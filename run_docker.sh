docker build --build-arg run_tests=1 -t="game-engine" .
docker run "game-engine"