//
// Created by Tulane on 12/9/22.
//

#include "Game.h"

using namespace tcg;

//bool Game::CheckCollision(Ship* &one, Asteroid* &two) // AABB - AABB collision
//{
////    int xx = abs(one->ship_pos[0].x- one->ship_pos[2].x);
////    std::cout<<"xx:"<<one->ship_pos[0].x- one->ship_pos[2].x;
//    // collision x-axis?
//    bool collisionX = one->state.cur_location.x + (one->ship_pos[2].x- one->ship_pos[0].x)>= two->state.cur_location.x &&
//    two->state.cur_location.x + (two->asteroid_bbox[1].x -two->asteroid_bbox[0].x )>= one->state.cur_location.x;
//    // collision y-axis?
//    bool collisionY = one->state.cur_location.y + (one->ship_pos[1].y- one->ship_pos[0].y) >= two->state.cur_location.y &&
//    two->state.cur_location.y + (two->asteroid_bbox[1].y -two->asteroid_bbox[0].y ) >= one->state.cur_location.y;
//    if(collisionX && collisionY == true){
//        game_over = true;
//    }
//    // collision only if on both axes
//    return collisionX && collisionY;
//}

bool Game::testIntersections(Car *c_inter, Ground *g_inter) {
    std::vector<vec2> car_boundaries;
    float c_width, c_height, g_width, g_height;

    c_width = c_inter->car_bbox[1].x - c_inter->car_bbox[0].x;
    c_height = c_inter->car_bbox[1].y - c_inter->car_bbox[0].y;

    g_width = g_inter->ground_bbox[1].x - g_inter->ground_bbox[0].x;
    g_height = g_inter->ground_bbox[1].y - g_inter->ground_bbox[0].y;

    tcg::vec2 c_p0, c_p1, c_p2, c_p3,
              g_p0, g_p1, g_p2, g_p3;
    c_p0 = vec2(c_inter->state.cur_location.x, c_inter->state.cur_location.y);
    c_p1 = vec2(c_inter->state.cur_location.x, c_inter->state.cur_location.y + c_height);
    c_p2 = vec2(c_inter->state.cur_location.x+c_width, c_inter->state.cur_location.y);
    c_p3 = vec2(c_inter->state.cur_location.x+c_width, c_inter->state.cur_location.y + c_height);

    g_p0 = vec2(g_inter->state.cur_location.x, g_inter->state.cur_location.y);
    g_p1 = vec2(g_inter->state.cur_location.x, g_inter->state.cur_location.y + g_height);
    g_p2 = vec2(g_inter->state.cur_location.x+g_width, g_inter->state.cur_location.y);
    g_p3 = vec2(g_inter->state.cur_location.x+g_width, g_inter->state.cur_location.y + g_height);

    bool in_x = false;
    bool in_y = false;

    if (c_p0.x < g_p2.x && c_p2.x > g_p0.x) {
        in_x = true;
    }

    if (c_p0.y < g_p1.y && c_p1.y > c_p0.y) {
        in_y = true;
    }

    if (in_y && in_x) {
//        std::cout << "True" << std::endl;
        return true;
    }
    else {
//        std::cout << "False" << std::endl;
        return false;
    }

//    std::cout<<"car min"<<car_min<<"\ncar max"<<car_max<<"\nground min"<<ground_min<<"\nground max"<<ground_max<<std::endl;
//    std::cout<<"car pos ("<<c_inter->state.cur_location.x<<", "<<c_inter->state.cur_location.y << ")\n";

}

void Game::attachWheels() {
    for (unsigned int i=0; i < wheels.size(); i ++){
        wheels[i]->gl_init();
    }
    float y_change = 0.05;
    wheels[0]->state.cur_location = vec2(car->state.cur_location.x - 0.05, car->state.cur_location.y - y_change);
    wheels[1]->state.cur_location = vec2(car->state.cur_location.x, car->state.cur_location.y - y_change);
    wheels[2]->state.cur_location = vec2(car->state.cur_location.x + 0.05, car->state.cur_location.y - y_change);


//    wheels[0]->state.cur_location = cur_location
//    wheel->state.cur_location = car->state.cur_location;
}


Game::Game() {
    car = new Car();
    ground = new Ground();
    alien1 = new Alien1();
    wheels.resize(3);
    wheels[0] = new Wheel(1);
    wheels[1] = new Wheel(2);
    wheels[2] = new Wheel(3);
}

//void Game::draw_game_over(mat4 proj){
//  
//  glUseProgram(GOGLvars.program);
//  glBindVertexArray( GOGLvars.vao );
//  glBindBuffer( GL_ARRAY_BUFFER, GOGLvars.buffer );
//  
//  glUniformMatrix4fv( GOGLvars.M_location, 1, GL_TRUE, proj);
//  
//  glBindTexture( GL_TEXTURE_2D, GOGLvars.texture  );
//  glDrawArrays( GL_TRIANGLE_STRIP, 0, 4 );
//  
//  glBindVertexArray(0);
//  glBindBuffer( GL_ARRAY_BUFFER, 0);
//
////  glfwSetWindowShouldClose(window, GLFW_TRUE);
////    game_over = true;
//    close_window = true;
//}
