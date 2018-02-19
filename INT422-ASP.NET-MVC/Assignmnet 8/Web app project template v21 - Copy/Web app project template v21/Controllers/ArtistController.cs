using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Web_app_project_template_v21.Controllers
{
    public class ArtistController : Controller
    {
        Manager m = new Manager();

        [AllowAnonymous]
        // GET: Artist
        public ActionResult Index()
        {
            return View(m.ArtistGetAll());
        }

        // GET: Artist/Details/5
        public ActionResult Details(int? id)
        {
            var o = m.ArtistGetByIdWithDetail(id.GetValueOrDefault());

            if (o == null)
            {
                return HttpNotFound();
            }
            else
            {
                return View(o);
            }
        }

        [Authorize(Roles = "Executive")]
        // GET: Artist/Create
        public ActionResult Create()
        {
            var form = new ArtistAddForm();
            form.GenreList = new SelectList(m.GenreGetAll(), "Id", "Name");

            return View(form);
        }

        // POST: Artist/Create
        [Authorize(Roles = "Executive")]
        [HttpPost]
        public ActionResult Create(ArtistAdd newItem)
        {
            newItem.Executive = HttpContext.User.Identity.Name;

            // Validate Input
            if (!ModelState.IsValid)
            {
                return View(newItem);
            }

            // Process Input
            var addedItem = m.ArtistAdd(newItem);

            if (addedItem == null)
            {
                return View(newItem);
            }
            else
            {
                return RedirectToAction("details", new { id = addedItem.Id });
            }
        }

        [Authorize(Roles = "Coordinator")]
        [Route("artist/{id}/addalbum")]
        // GET: Artist/Create
        public ActionResult AddAlbum(int? Id)
        {

            var a = m.ArtistGetByIdWithDetail(Id.GetValueOrDefault());

            var vals = new List<int> { a.Id };

            var form = new AlbumAddForm();

            form.GenreList = new SelectList(m.GenreGetAll(), "Id", "Name");

            form.TrackList = new MultiSelectList(
                items: m.TrackGetAll(), dataTextField: "Name", dataValueField: "Id");

            form.ArtistList = new MultiSelectList(
                items: m.ArtistGetAll(), dataTextField: "Name", dataValueField: "Id", selectedValues: vals);

            form.ArtistName = a.Name;

            return View(form);
        }

        // POST: Artist/Create
        [Authorize(Roles = "Coordinator")]
        [Route("artist/{id}/addalbum")]
        [HttpPost]
        public ActionResult AddAlbum(AlbumAdd newItem)
        {
            newItem.Coordinator = HttpContext.User.Identity.Name;

            // Validate Input
            if (!ModelState.IsValid)
            {
                return View(newItem);
            }

            // Process Input
            var addedItem = m.AlbumAdd(newItem);

            if (addedItem == null)
            {
                return View(newItem);
            }
            else
            {
                return RedirectToAction("../album/details", new { id = addedItem.Id });
            }
        }

        //Edit and Delete not necessary
    }
}
