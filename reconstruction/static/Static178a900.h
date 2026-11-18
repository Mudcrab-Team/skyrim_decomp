// Source exposure: binary-analysis; no external implementation source reused.
// Static178a900, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178a900;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178a900*);
    virtual void release(Static178a900*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178a900*);
struct Static178a900 {
    void* value;
    Static178a900();
    ~Static178a900() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
