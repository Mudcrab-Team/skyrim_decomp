// Source exposure: binary-analysis; no external implementation source reused.
// Static175b340, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175b340;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175b340*);
    virtual void release(Static175b340*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175b340*);
struct Static175b340 {
    void* value;
    Static175b340();
    ~Static175b340() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
