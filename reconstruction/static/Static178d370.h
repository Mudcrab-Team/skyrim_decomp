// Source exposure: binary-analysis; no external implementation source reused.
// Static178d370, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178d370;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178d370*);
    virtual void release(Static178d370*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178d370*);
struct Static178d370 {
    void* value;
    Static178d370();
    ~Static178d370() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
