// Source exposure: binary-analysis; no external implementation source reused.
// Static176a480, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176a480;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176a480*);
    virtual void release(Static176a480*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176a480*);
struct Static176a480 {
    void* value;
    Static176a480();
    ~Static176a480() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
