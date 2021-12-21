// Copyright (c) 2019 Martyn Afford
// Licensed under the MIT licence

#include <chrono>
#include <iostream>
#include <random>
#include "poisson_disc_distribution.hpp"

int* FPD_Random(int width, int height, double min_distance) {
    //constexpr auto width = 6000;
    //constexpr auto height = 4000;

    int *map = new int [height*width];
    /*for (int i = 0; i < height; i++) {
        map[i] = new int[width];
    }*/

    auto seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::default_random_engine engine{seed};
    std::uniform_real_distribution<float> distribution{0, 1};

    bridson::config conf;
    conf.width = width;
    conf.height = height;
    conf.min_distance = min_distance;

    bridson::poisson_disc_distribution(
            conf,
            // random
            [&engine, &distribution](float range) {
                return distribution(engine) * range;
            },
            // in_area
            [](bridson::point p, bridson::config conf) {
                return p.x > 0 && p.x < conf.width && p.y > 0 && p.y < conf.height;
            },
            // output
            [&map](bridson::point p, int width) {
                map[static_cast<int>(p.y) * width + static_cast<int>(p.x)] = 1;
            });

    return map;
}

extern "C"{
    int* get_FPD_Random(int width, int height, double min_distance){
        return FPD_Random(width, height, min_distance);
    }
}