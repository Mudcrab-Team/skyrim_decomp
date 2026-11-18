// Source exposure: binary-analysis; no external implementation source reused.
// Static178a300, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178a300;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178a300*);
    virtual void release(Static178a300*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178a300*);
struct Static178a300 {
    void* value;
    Static178a300();
    ~Static178a300() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
