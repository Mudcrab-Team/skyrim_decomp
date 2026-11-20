// Source exposure: binary-analysis; no external implementation source reused.
// Static175b980, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175b980;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175b980*);
    virtual void release(Static175b980*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175b980*);
struct Static175b980 {
    void* value;
    Static175b980();
    ~Static175b980() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
