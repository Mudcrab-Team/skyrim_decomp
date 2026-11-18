// Source exposure: binary-analysis; no external implementation source reused.
// Static175b480, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175b480;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175b480*);
    virtual void release(Static175b480*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175b480*);
struct Static175b480 {
    void* value;
    Static175b480();
    ~Static175b480() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
