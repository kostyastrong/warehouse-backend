//
// Created by maincpp on 18.11.2021.
//

#include "Application.h"
std::unordered_map<std::string, int> Application::needs_;

void Application::add() {
    if (added_) return;
    for (std::pair<const std::basic_string<char>, int>& i : data_) {
        Application::needs_[i.first] += i.second;
    }
    added_ = true;
}

Application::Application(std::unordered_map<std::string, int> data):
data_(std::move(data)){
    add();
}

void Application::clearNeeds() {
    Application::needs_.clear();
}
