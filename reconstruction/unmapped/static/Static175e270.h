// Source exposure: binary-analysis; no external implementation source reused.
// Static175e270, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175e270;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175e270*);
    virtual void release(Static175e270*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175e270*);
struct Static175e270 {
    void* value;
    Static175e270();
    ~Static175e270() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
