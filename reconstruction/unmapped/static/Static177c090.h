// Source exposure: binary-analysis; no external implementation source reused.
// Static177c090, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177c090;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177c090*);
    virtual void release(Static177c090*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177c090*);
struct Static177c090 {
    void* value;
    Static177c090();
    ~Static177c090() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
