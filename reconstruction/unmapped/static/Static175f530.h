// Source exposure: binary-analysis; no external implementation source reused.
// Static175f530, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175f530;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175f530*);
    virtual void release(Static175f530*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175f530*);
struct Static175f530 {
    void* value;
    Static175f530();
    ~Static175f530() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
