function msg_display(elem_1, elem_2, msg, div)
{
	elem_1.innerHTML = msg;
	elem_1.style.display = "block";
	if (msg === "Check your mail for the validation" || msg === "Password changed check your mail")
		elem_1.style.color = "#4d9f49";
	else
		elem_1.style.color = "#d44c2f";
	if (elem_2 != null)
		elem_2.style.display = "none";
	if (elem_2 != null)
		div.style.marginBottom = "8px";
	else
		div.style.marginBottom = "145px";
}

function msg_display_change(elem_1, msg)
{
	elem_1.innerHTML = msg;
	elem_1.style.display = "block";
	if (msg === "Change success")
		elem_1.style.color = "#4d9f49";
	else
		elem_1.style.color = "#d44c2f";
}

function msg_hide(elem_1, elem_2, div)
{
	elem_1.style.display = "none";
	elem_2.style.display = "none";
	div.style.marginTop = "8px";
}
