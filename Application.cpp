//
// Created by maincpp on 18.11.2021.
//

#include "Application.h"

Report::Report(std::unordered_map<std::string, int>& data):
    data_(std::move(data)){}

Report::Report(){
    data_ = std::unordered_map<std::string, int> {};
}

const std::unordered_map<std::string, int> &Report::getData() {
    return data_;
}

Report::Report(const Report &a): data_(a.data_){}

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

Application::Application() {}

void Application::addProd(std::string name, int num) {
    needs_[name] += num;
    data_[name] += num;
}

Application::Application(const Application &a): Report(a), added_(true){}

int Control::getType() const {
    return type_;
}

Control::Control(std::unordered_map<std::string, int> &data, int type):
Report(data),
type_(type){}

void Control::setType(int a) {
    type_ = a;
}

Control::Control(std::vector<Report *> &data, int type): type_(type){
    std::unordered_map<std::string, int> order;
    for (Report* i : data) {
        for (const std::pair<const std::string, int>& j : i->getData()) {
            order[j.first] += j.second;
        }
    }
    data_ = std::move(order);
}
