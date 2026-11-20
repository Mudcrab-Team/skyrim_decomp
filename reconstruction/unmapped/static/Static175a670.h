// Source exposure: binary-analysis; no external implementation source reused.
// Static175a670, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175a670;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175a670*);
    virtual void release(Static175a670*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175a670*);
struct Static175a670 {
    void* value;
    Static175a670();
    ~Static175a670() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
