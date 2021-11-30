//
// Created by maincpp on 18.11.2021.
//

#include "Application.h"

Report::Report(std::unordered_map<std::string, int>& data):
    data_(std::move(data)){}

std::unordered_map<std::string, int> Application::needs_;

void Application::add() {
    if (added_) return;
    for (std::pair<const std::basic_string<char>, int>& i : data_) {
        Application::needs_[i.first] += i.second;
    }
    added_ = true;
}

Application::Application(std::unordered_map<std::string, int>& data):
    Report(data){
    add();
}

void Application::clearNeeds() {
    Application::needs_.clear();
}

int Control::getType() const {
    return type_;
}

Control::Control(std::unordered_map<std::string, int> &data, int type):
Report(data),
type_(type){}
