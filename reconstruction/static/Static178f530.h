// Source exposure: binary-analysis; no external implementation source reused.
// Static178f530, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178f530;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178f530*);
    virtual void release(Static178f530*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178f530*);
struct Static178f530 {
    void* value;
    Static178f530();
    ~Static178f530() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
