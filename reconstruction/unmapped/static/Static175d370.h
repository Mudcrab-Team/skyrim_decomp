// Source exposure: binary-analysis; no external implementation source reused.
// Static175d370, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175d370;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175d370*);
    virtual void release(Static175d370*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175d370*);
struct Static175d370 {
    void* value;
    Static175d370();
    ~Static175d370() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
