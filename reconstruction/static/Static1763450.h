// Source exposure: binary-analysis; no external implementation source reused.
// Static1763450, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1763450;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1763450*);
    virtual void release(Static1763450*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1763450*);
struct Static1763450 {
    void* value;
    Static1763450();
    ~Static1763450() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
