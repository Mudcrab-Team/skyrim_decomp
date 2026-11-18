// Source exposure: binary-analysis; no external implementation source reused.
// Static175af80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175af80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175af80*);
    virtual void release(Static175af80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175af80*);
struct Static175af80 {
    void* value;
    Static175af80();
    ~Static175af80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
