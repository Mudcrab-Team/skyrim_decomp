// Source exposure: binary-analysis; no external implementation source reused.
// Static174a480, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174a480;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174a480*);
    virtual void release(Static174a480*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174a480*);
struct Static174a480 {
    void* value;
    Static174a480();
    ~Static174a480() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
