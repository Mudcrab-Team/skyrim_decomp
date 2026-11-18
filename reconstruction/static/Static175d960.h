// Source exposure: binary-analysis; no external implementation source reused.
// Static175d960, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175d960;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175d960*);
    virtual void release(Static175d960*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175d960*);
struct Static175d960 {
    void* value;
    Static175d960();
    ~Static175d960() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
