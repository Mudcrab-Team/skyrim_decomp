// Source exposure: binary-analysis; no external implementation source reused.
// Static176b380, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176b380;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176b380*);
    virtual void release(Static176b380*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176b380*);
struct Static176b380 {
    void* value;
    Static176b380();
    ~Static176b380() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
