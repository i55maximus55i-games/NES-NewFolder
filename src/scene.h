#ifndef _SCENE_H_
#define _SCENE_H_

struct scene
{
    void (*start_scene)();
    void (*render_scene)();
    void (*end_scene)();
};

struct scene current_scene;

void set_scene(struct scene * penis)
{
    current_scene.end_scene();
    
    current_scene.start_scene = penis->start_scene;
    current_scene.render_scene = penis->render_scene;
    current_scene.end_scene = penis->end_scene;

    current_scene.start_scene();
}

#endif