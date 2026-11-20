// Source exposure: binary-analysis; no external implementation source reused.
// Static175e310, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175e310;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175e310*);
    virtual void release(Static175e310*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175e310*);
struct Static175e310 {
    void* value;
    Static175e310();
    ~Static175e310() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
