// Source exposure: binary-analysis; no external implementation source reused.
// Static1755850, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1755850;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1755850*);
    virtual void release(Static1755850*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1755850*);
struct Static1755850 {
    void* value;
    Static1755850();
    ~Static1755850() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
