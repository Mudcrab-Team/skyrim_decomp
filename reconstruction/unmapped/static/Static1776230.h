// Source exposure: binary-analysis; no external implementation source reused.
// Static1776230, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1776230;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1776230*);
    virtual void release(Static1776230*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1776230*);
struct Static1776230 {
    void* value;
    Static1776230();
    ~Static1776230() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
