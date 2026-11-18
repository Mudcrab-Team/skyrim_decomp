// Source exposure: binary-analysis; no external implementation source reused.
// Static177bd70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177bd70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177bd70*);
    virtual void release(Static177bd70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177bd70*);
struct Static177bd70 {
    void* value;
    Static177bd70();
    ~Static177bd70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
