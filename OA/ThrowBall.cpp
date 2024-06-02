#include <iostream>
#include <vector>
#include <unordered_map>

int throw_balls(int start, const std::vector<int>& receiver, int seconds) {
    int current_player = start;
    std::unordered_map<int, int> already_seen;

    for (int i = 0; i < seconds; ++i) {
        current_player = receiver[current_player - 1];
        if (already_seen.find(current_player) != already_seen.end()) {
            int loop_length = i - already_seen[current_player];
            int remaining = seconds - i;
            return throw_balls(current_player, receiver, remaining % loop_length);
        } else {
            already_seen[current_player] = i;
        }
    }
    return current_player -1;
}

int main() {
    std::vector<int> receiver = {2, 4, 1, 5, 3};  // Example receiver vector
    int start = 1;  // Friend 1 starts with the ball
    int seconds = 6;  // Example seconds

    int result = throw_balls(start, receiver, seconds);
    std::cout << "The friend with the ball after " << seconds << " seconds is: Friend " << result << std::endl;

    return 0;
}