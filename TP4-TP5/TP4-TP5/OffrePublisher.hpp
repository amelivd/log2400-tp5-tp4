#pragma once

#include "OffreSubscriber.hpp"
#include "ComposantBDOR.hpp"
#include <vector>

class OffrePublisher {
public:
    OffrePublisher() = default;
    virtual ~OffrePublisher() = default;

    void subscribe(OffreSubscriber* subscriber) {
        subscribers.push_back(subscriber);
    }

    void unsubscribe(OffreSubscriber* subscriber) {
        auto it = std::find(subscribers.begin(), subscribers.end(), subscriber);
        if (it != subscribers.end()) {
            subscribers.erase(it);
        }
    }

    void notifierDecoration(ComposantBDOR* nouvelleOffre) {
        for (OffreSubscriber* subscriber : subscribers) {
            subscriber->update(nouvelleOffre);
        }
    }

    int getNbSubscribers() const {
        return subscribers.size();
    }

private:
    std::vector<OffreSubscriber*> subscribers;
};