// Source exposure: binary-analysis; no external implementation source reused.
// Static175b700, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175b700;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175b700*);
    virtual void release(Static175b700*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175b700*);
struct Static175b700 {
    void* value;
    Static175b700();
    ~Static175b700() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
